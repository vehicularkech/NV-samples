/* Generated by wayland-scanner 1.11.0 */

#ifndef IVI_SHARE_SERVER_PROTOCOL_H
#define IVI_SHARE_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_ivi_share The ivi_share protocol
 * @section page_ifaces_ivi_share Interfaces
 * - @subpage page_iface_ivi_share - get handle to manipulate ivi_surface
 * - @subpage page_iface_ivi_share_surface - extension interface for sharing a ivi_surface
 * @section page_copyright_ivi_share Copyright
 * <pre>
 *
 * Copyright (c) 2012 Advanced Driver Information Technology.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * </pre>
 */
struct ivi_share;
struct ivi_share_surface;

/**
 * @page page_iface_ivi_share ivi_share
 * @section page_iface_ivi_share_desc Description
 *
 * get handle ID to manipulate shared ivi_surface. The host ivi application
 * can get trigger of update of the ivi_surface from client to draw it in host's
 * content. Additionally the interface allows host ivi application to send
 * transformed input coordinates to client because the coordinate is transformed
 * outside of compositor.
 * @section page_iface_ivi_share_api API
 * See @ref iface_ivi_share.
 */
/**
 * @defgroup iface_ivi_share The ivi_share interface
 *
 * get handle ID to manipulate shared ivi_surface. The host ivi application
 * can get trigger of update of the ivi_surface from client to draw it in host's
 * content. Additionally the interface allows host ivi application to send
 * transformed input coordinates to client because the coordinate is transformed
 * outside of compositor.
 */
extern const struct wl_interface ivi_share_interface;
/**
 * @page page_iface_ivi_share_surface ivi_share_surface
 * @section page_iface_ivi_share_surface_desc Description
 *
 * @section page_iface_ivi_share_surface_api API
 * See @ref iface_ivi_share_surface.
 */
/**
 * @defgroup iface_ivi_share_surface The ivi_share_surface interface
 *
 */
extern const struct wl_interface ivi_share_surface_interface;

/**
 * @ingroup iface_ivi_share
 * @struct ivi_share_interface
 */
struct ivi_share_interface {
	/**
	 * @param surface_id IVI id which is global in a system
	 */
	void (*get_ivi_share_surface)(struct wl_client *client,
				      struct wl_resource *resource,
				      uint32_t id,
				      uint32_t surface_id);
};


#ifndef IVI_SHARE_SURFACE_TYPE_ENUM
#define IVI_SHARE_SURFACE_TYPE_ENUM
/**
 * @ingroup iface_ivi_share_surface
 * name type
 *
 * The ivi-share is dependent on an architecture how to share graphic
 * buffer inter processes. This informs Host ivi_application which way shall
 * be used in its own system. The most popular way is gbm now.
 */
enum ivi_share_surface_type {
	IVI_SHARE_SURFACE_TYPE_GBM = 0,
	IVI_SHARE_SURFACE_TYPE_UNKNOWN = 1,
};
#endif /* IVI_SHARE_SURFACE_TYPE_ENUM */

#ifndef IVI_SHARE_SURFACE_FORMAT_ENUM
#define IVI_SHARE_SURFACE_FORMAT_ENUM
/**
 * @ingroup iface_ivi_share_surface
 * share surface format
 */
enum ivi_share_surface_format {
	IVI_SHARE_SURFACE_FORMAT_ARGB8888 = 0,
	IVI_SHARE_SURFACE_FORMAT_XRGB8888 = 1,
	IVI_SHARE_SURFACE_FORMAT_UNKNOWN = 2,
};
#endif /* IVI_SHARE_SURFACE_FORMAT_ENUM */

#ifndef IVI_SHARE_SURFACE_INPUT_CAPS_ENUM
#define IVI_SHARE_SURFACE_INPUT_CAPS_ENUM
/**
 * @ingroup iface_ivi_share_surface
 * input capability bitmask
 */
enum ivi_share_surface_input_caps {
	/**
	 * Shared surface can receive a pointer event
	 */
	IVI_SHARE_SURFACE_INPUT_CAPS_POINTER = 1,
	/**
	 * Shared surface can receive a keyboard event
	 */
	IVI_SHARE_SURFACE_INPUT_CAPS_KEYBOARD = 2,
	/**
	 * Shared surface can receive a touch event
	 */
	IVI_SHARE_SURFACE_INPUT_CAPS_TOUCH = 4,
};
#endif /* IVI_SHARE_SURFACE_INPUT_CAPS_ENUM */

#ifndef IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_ENUM
#define IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_ENUM
/**
 * @ingroup iface_ivi_share_surface
 * state of shared surface
 */
enum ivi_share_surface_share_surface_state {
	/**
	 * the surface which shared is not exist
	 */
	IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_NOT_EXIST = 1,
	/**
	 * the surface which shared has been destroyed
	 */
	IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_DESTROYED = 2,
	/**
	 * the surface is unsited for share
	 */
	IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_INVALID_SURFACE = 3,
};
#endif /* IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_ENUM */

/**
 * @ingroup iface_ivi_share_surface
 * @struct ivi_share_surface_interface
 */
struct ivi_share_surface_interface {
	/**
	 * delete share surface
	 *
	 * Deletes the surface and invalidates its object ID.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * redirect touch down event
	 *
	 * 
	 * @param id the unique ID of this touch point
	 * @param x x coordinate in shared surface-relative coordinates
	 * @param y y coordinate in shared surface-relative coordinates
	 */
	void (*redirect_touch_down)(struct wl_client *client,
				    struct wl_resource *resource,
				    uint32_t serial,
				    int32_t id,
				    wl_fixed_t x,
				    wl_fixed_t y);
	/**
	 * redirect end of touch event sequence
	 *
	 * 
	 * @param id the unique ID of this touch point
	 */
	void (*redirect_touch_up)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t serial,
				  int32_t id);
	/**
	 * redirect update of touch point coordinates
	 *
	 * 
	 * @param id the unique ID of this touch point
	 * @param x x coordinate in shared surface-relative coordinates
	 * @param y y coordinate in shared surface-relative coordinates
	 */
	void (*redirect_touch_motion)(struct wl_client *client,
				      struct wl_resource *resource,
				      int32_t id,
				      wl_fixed_t x,
				      wl_fixed_t y);
	/**
	 * end of touch frame event
	 *
	 * 
	 */
	void (*redirect_touch_frame)(struct wl_client *client,
				     struct wl_resource *resource);
	/**
	 * touch session canceled
	 *
	 * 
	 */
	void (*redirect_touch_cancel)(struct wl_client *client,
				      struct wl_resource *resource);
};

#define IVI_SHARE_SURFACE_DAMAGE	0
#define IVI_SHARE_SURFACE_CONFIGURE	1
#define IVI_SHARE_SURFACE_INPUT_CAPABILITIES	2
#define IVI_SHARE_SURFACE_SHARE_SURFACE_STATE	3

/**
 * @ingroup iface_ivi_share_surface
 */
#define IVI_SHARE_SURFACE_DAMAGE_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_share_surface
 */
#define IVI_SHARE_SURFACE_CONFIGURE_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_share_surface
 */
#define IVI_SHARE_SURFACE_INPUT_CAPABILITIES_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_share_surface
 */
#define IVI_SHARE_SURFACE_SHARE_SURFACE_STATE_SINCE_VERSION	1

/**
 * @ingroup iface_ivi_share_surface
 * Sends an damage event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_share_surface_send_damage(struct wl_resource *resource_, uint32_t name)
{
	wl_resource_post_event(resource_, IVI_SHARE_SURFACE_DAMAGE, name);
}

/**
 * @ingroup iface_ivi_share_surface
 * Sends an configure event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_share_surface_send_configure(struct wl_resource *resource_, uint32_t type, uint32_t width, uint32_t height, uint32_t stride, uint32_t format)
{
	wl_resource_post_event(resource_, IVI_SHARE_SURFACE_CONFIGURE, type, width, height, stride, format);
}

/**
 * @ingroup iface_ivi_share_surface
 * Sends an input_capabilities event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_share_surface_send_input_capabilities(struct wl_resource *resource_, uint32_t capabilities)
{
	wl_resource_post_event(resource_, IVI_SHARE_SURFACE_INPUT_CAPABILITIES, capabilities);
}

/**
 * @ingroup iface_ivi_share_surface
 * Sends an share_surface_state event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_share_surface_send_share_surface_state(struct wl_resource *resource_, uint32_t state)
{
	wl_resource_post_event(resource_, IVI_SHARE_SURFACE_SHARE_SURFACE_STATE, state);
}

#ifdef  __cplusplus
}
#endif

#endif