/*
 * Copyright (C) 2015 Endless Mobile
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 * Written by:
 *     Jasper St. Pierre <jstpierre@mecheye.net>
 */

#pragma once

#include <gtk/gtk.h>

#define WAKEFIELD_TYPE_COMPOSITOR            (wakefield_compositor_get_type ())
#define WAKEFIELD_COMPOSITOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), WAKEFIELD_TYPE_COMPOSITOR, WakefieldCompositor))
#define WAKEFIELD_COMPOSITOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  WAKEFIELD_TYPE_COMPOSITOR, WakefieldCompositorClass))
#define WAKEFIELD_IS_COMPOSITOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), WAKEFIELD_TYPE_COMPOSITOR))
#define WAKEFIELD_IS_COMPOSITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  WAKEFIELD_TYPE_COMPOSITOR))
#define WAKEFIELD_COMPOSITOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  WAKEFIELD_TYPE_COMPOSITOR, WakefieldCompositorClass))

typedef struct _WakefieldCompositor        WakefieldCompositor;
typedef struct _WakefieldCompositorClass   WakefieldCompositorClass;

struct _WakefieldCompositor
{
  GtkWidget parent;
};

struct _WakefieldCompositorClass
{
  GtkWidgetClass parent_class;
};

GType wakefield_compositor_get_type (void) G_GNUC_CONST;

WakefieldCompositor *wakefield_compositor_new              (void);
const char *         wakefield_compositor_add_socket_auto  (WakefieldCompositor *compositor,
                                                            GError              **error);
gboolean             wakefield_compositor_add_socket       (WakefieldCompositor *compositor,
                                                            const char          *name,
                                                            GError              **error);
int                  wakefield_compositor_create_client_fd (WakefieldCompositor *compositor,
                                                            GDestroyNotify       destroy_notify,
                                                            gpointer             user_data,
                                                            GError             **error);
