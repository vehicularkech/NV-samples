/* Generated by wayland-scanner 1.11.0 */

#ifndef WESTON_SCREENSHOOTER_CLIENT_PROTOCOL_H
#define WESTON_SCREENSHOOTER_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_weston_screenshooter The weston_screenshooter protocol
 * @section page_ifaces_weston_screenshooter Interfaces
 * - @subpage page_iface_weston_screenshooter - 
 */
struct weston_screenshooter;
struct wl_buffer;
struct wl_output;

/**
 * @page page_iface_weston_screenshooter weston_screenshooter
 * @section page_iface_weston_screenshooter_api API
 * See @ref iface_weston_screenshooter.
 */
/**
 * @defgroup iface_weston_screenshooter The weston_screenshooter interface
 */
extern const struct wl_interface weston_screenshooter_interface;

/**
 * @ingroup iface_weston_screenshooter
 * @struct weston_screenshooter_listener
 */
struct weston_screenshooter_listener {
	/**
	 */
	void (*done)(void *data,
		     struct weston_screenshooter *weston_screenshooter);
};

/**
 * @ingroup weston_screenshooter_iface
 */
static inline int
weston_screenshooter_add_listener(struct weston_screenshooter *weston_screenshooter,
				  const struct weston_screenshooter_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) weston_screenshooter,
				     (void (**)(void)) listener, data);
}

#define WESTON_SCREENSHOOTER_SHOOT	0

/**
 * @ingroup iface_weston_screenshooter
 */
#define WESTON_SCREENSHOOTER_SHOOT_SINCE_VERSION	1

/** @ingroup iface_weston_screenshooter */
static inline void
weston_screenshooter_set_user_data(struct weston_screenshooter *weston_screenshooter, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) weston_screenshooter, user_data);
}

/** @ingroup iface_weston_screenshooter */
static inline void *
weston_screenshooter_get_user_data(struct weston_screenshooter *weston_screenshooter)
{
	return wl_proxy_get_user_data((struct wl_proxy *) weston_screenshooter);
}

static inline uint32_t
weston_screenshooter_get_version(struct weston_screenshooter *weston_screenshooter)
{
	return wl_proxy_get_version((struct wl_proxy *) weston_screenshooter);
}

/** @ingroup iface_weston_screenshooter */
static inline void
weston_screenshooter_destroy(struct weston_screenshooter *weston_screenshooter)
{
	wl_proxy_destroy((struct wl_proxy *) weston_screenshooter);
}

/**
 * @ingroup iface_weston_screenshooter
 */
static inline void
weston_screenshooter_shoot(struct weston_screenshooter *weston_screenshooter, struct wl_output *output, struct wl_buffer *buffer)
{
	wl_proxy_marshal((struct wl_proxy *) weston_screenshooter,
			 WESTON_SCREENSHOOTER_SHOOT, output, buffer);
}

#ifdef  __cplusplus
}
#endif

#endif
