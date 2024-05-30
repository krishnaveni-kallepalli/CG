#include <alsa/asoundlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file.wav>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;
    unsigned int rate = 44100; // Default sample rate
    int channels = 2;          // Stereo
    snd_pcm_hw_params_t *params;
    int dir, rc;
    snd_pcm_uframes_t frames_count;
    char *buffer;
    int size, loops;

    // Open PCM device for playback.
    rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (rc < 0) {
        fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
        return 1;
    }

    // Allocate a hardware parameters object.
    snd_pcm_hw_params_malloc(&params);

    // Fill it in with default values.
    snd_pcm_hw_params_any(handle, params);

    // Set the desired hardware parameters.
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(handle, params, channels);
    snd_pcm_hw_params_set_rate_near(handle, params, &rate, &dir);

    // Write the parameters to the driver.
    rc = snd_pcm_hw_params(handle, params);
    if (rc < 0) {
        fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
        return 1;
    }

    // Use a buffer large enough to hold one period.
    snd_pcm_hw_params_get_period_size(params, &frames_count, &dir);
    size = frames_count * channels * 2; // 2 bytes/sample, 2 channels
    buffer = (char *)malloc(size);

    // Open the WAV file
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    // Skip the WAV header
    fseek(fp, 44, SEEK_SET);

    // We want to loop over the audio file indefinitely
    while (1) {
        // Read frames from the file
        rc = fread(buffer, 1, size, fp);
        if (rc == 0) {
            // Rewind to the start of the file
            fseek(fp, 44, SEEK_SET);
            continue;
        }

        frames = snd_pcm_writei(handle, buffer, frames_count);
        if (frames < 0)
            frames = snd_pcm_recover(handle, frames, 0);
        if (frames < 0) {
            fprintf(stderr, "snd_pcm_writei failed: %s\n", snd_strerror(frames));
            break;
        }
        if (frames > 0 && frames < (long)frames_count)
            printf("Short write (expected %li, wrote %li)\n", (long)frames_count, frames);
    }

    // Clean up
    fclose(fp);
    free(buffer);
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    snd_pcm_hw_params_free(params);

    return 0;
}

