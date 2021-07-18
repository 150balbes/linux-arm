// SPDX-License-Identifier: GPL-2.0+
//
// Copyright (C) 2021 Oleg Ivanov <balbes-150@yandex.ru>

/*
 * Keytable for the Firefly Station SBC remote control
 */

#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table station[] = {
	{ 0x14, KEY_POWER },

	{ 0x03, KEY_UP },
	{ 0x02, KEY_DOWN },
	{ 0x0e, KEY_LEFT },
	{ 0x1a, KEY_RIGHT },
	{ 0x07, KEY_ENTER },

	{ 0x01, KEY_BACK },
	{ 0x5b, KEY_MUTE },
	{ 0x13, KEY_MENU },

	{ 0x58, KEY_VOLUMEDOWN },
	{ 0x0b, KEY_VOLUMEUP },

	{ 0x48, KEY_HOME },
};

static struct rc_map_list station_map = {
	.map = {
		.scan     = station,
		.size     = ARRAY_SIZE(station),
		.rc_proto = RC_PROTO_NEC,
		.name     = RC_MAP_STATION,
	}
};

static int __init init_rc_map_station(void)
{
	return rc_map_register(&station_map);
}

static void __exit exit_rc_map_station(void)
{
	rc_map_unregister(&station_map);
}

module_init(init_rc_map_station)
module_exit(exit_rc_map_station)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oleg Ivanov <balbes-150@yandex.ru>");
