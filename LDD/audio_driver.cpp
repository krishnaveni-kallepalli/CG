#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/sound.h>
#include<linux/soundcard.h>

#define DEVICE_NAME "simple_audio"
#define BUFFER_LEN = 80
static int __init aud_start(void)
{

}

static void __exit aud_end(void)
{

}


module_init(aud_start);
module_exit(aud_end);
