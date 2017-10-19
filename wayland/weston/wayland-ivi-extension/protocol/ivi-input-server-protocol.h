/* Generated by wayland-scanner 1.11.0 */

#ifndef IVI_INPUT_SERVER_PROTOCOL_H
#define IVI_INPUT_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_ivi_input The ivi_input protocol
 * @section page_ifaces_ivi_input Interfaces
 * - @subpage page_iface_ivi_input - controller interface to the input system
 * @section page_copyright_ivi_input Copyright
 * <pre>
 *
 * Copyright (c) 2015 Codethink Ltd
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
struct ivi_input;

/**
 * @page page_iface_ivi_input ivi_input
 * @section page_iface_ivi_input_desc Description
 *
 * This includes handling the existence of seats, seat capabilities,
 * seat acceptance and input focus.
 * @section page_iface_ivi_input_api API
 * See @ref iface_ivi_input.
 */
/**
 * @defgroup iface_ivi_input The ivi_input interface
 *
 * This includes handling the existence of seats, seat capabilities,
 * seat acceptance and input focus.
 */
extern const struct wl_interface ivi_input_interface;

/**
 * @ingroup iface_ivi_input
 * @struct ivi_input_interface
 */
struct ivi_input_interface {
	/**
	 * set input focus for a given surface ID
	 *
	 * Set input focus state of surface in ivi compositor. If the
	 * surface has input focus, all non-graphical inputs (e.g.
	 * keyboard) are directed to the application providing the content
	 * for this surface. Multiple surfaces can have input focus at a
	 * time. If argument enabled is ILM_TRUE, input focus for this
	 * surface is enabled. If argument enabled is not ILM_TRUE, the
	 * input focus from this surface is removed.
	 */
	void (*set_input_focus)(struct wl_client *client,
				struct wl_resource *resource,
				uint32_t surface,
				uint32_t device,
				int32_t enabled);
	/**
	 * set a surface's input acceptance for a seat
	 *
	 * Set input acceptance of one seat for a surface. Surfaces may
	 * accept input acceptance from multiple seats at once. If argument
	 * 'accepted' is ILM_TRUE, the given seat's name will be added to
	 * the list of accepted seats. If argument 'accepted' is not
	 * ILM_TRUE, the given seat's name will be removed from the list of
	 * accepted seats.
	 */
	void (*set_input_acceptance)(struct wl_client *client,
				     struct wl_resource *resource,
				     uint32_t surface,
				     const char *seat,
				     int32_t accepted);
};

#define IVI_INPUT_SEAT_CREATED	0
#define IVI_INPUT_SEAT_CAPABILITIES	1
#define IVI_INPUT_SEAT_DESTROYED	2
#define IVI_INPUT_INPUT_FOCUS	3
#define IVI_INPUT_INPUT_ACCEPTANCE	4

/**
 * @ingroup iface_ivi_input
 */
#define IVI_INPUT_SEAT_CREATED_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_input
 */
#define IVI_INPUT_SEAT_CAPABILITIES_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_input
 */
#define IVI_INPUT_SEAT_DESTROYED_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_input
 */
#define IVI_INPUT_INPUT_FOCUS_SINCE_VERSION	1
/**
 * @ingroup iface_ivi_input
 */
#define IVI_INPUT_INPUT_ACCEPTANCE_SINCE_VERSION	1

/**
 * @ingroup iface_ivi_input
 * Sends an seat_created event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_input_send_seat_created(struct wl_resource *resource_, const char *name, uint32_t capabilities)
{
	wl_resource_post_event(resource_, IVI_INPUT_SEAT_CREATED, name, capabilities);
}

/**
 * @ingroup iface_ivi_input
 * Sends an seat_capabilities event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_input_send_seat_capabilities(struct wl_resource *resource_, const char *name, uint32_t capabilities)
{
	wl_resource_post_event(resource_, IVI_INPUT_SEAT_CAPABILITIES, name, capabilities);
}

/**
 * @ingroup iface_ivi_input
 * Sends an seat_destroyed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_input_send_seat_destroyed(struct wl_resource *resource_, const char *name)
{
	wl_resource_post_event(resource_, IVI_INPUT_SEAT_DESTROYED, name);
}

/**
 * @ingroup iface_ivi_input
 * Sends an input_focus event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_input_send_input_focus(struct wl_resource *resource_, uint32_t surface, uint32_t device, int32_t enabled)
{
	wl_resource_post_event(resource_, IVI_INPUT_INPUT_FOCUS, surface, device, enabled);
}

/**
 * @ingroup iface_ivi_input
 * Sends an input_acceptance event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
ivi_input_send_input_acceptance(struct wl_resource *resource_, uint32_t surface, const char *seat, int32_t accepted)
{
	wl_resource_post_event(resource_, IVI_INPUT_INPUT_ACCEPTANCE, surface, seat, accepted);
}

#ifdef  __cplusplus
}
#endif

#endif
