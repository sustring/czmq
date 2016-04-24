/*  =========================================================================
    czmq_classes - private header file

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#ifndef CZMQ_CLASSES_H_INCLUDED
#define CZMQ_CLASSES_H_INCLUDED

//  Platform definitions, must come first
#include "platform.h"

//  External API
#include "../include/czmq.h"

//  Internal API
#include "zgossip_msg.h"

//  *** To avoid double-definitions, only define if building without draft ***
#ifndef CZMQ_BUILD_DRAFT_API

//  *** Draft method, defined for internal use only ***
//  Unset certificate metadata.
CZMQ_EXPORT void
    zcert_unset_meta (zcert_t *self, const char *name);

//  *** Draft callbacks, defined for internal use only ***
// Loaders retrieve certificates from an arbitrary source.
typedef void (zcertstore_loader) (
    zcertstore_t *self);
// Destructor for loader state.
typedef void (zcertstore_destructor) (
    void **self_p);

//  *** Draft method, defined for internal use only ***
//  Override the default disk loader with a custom loader fn.
CZMQ_EXPORT void
    zcertstore_set_loader (zcertstore_t *self, zcertstore_loader loader, zcertstore_destructor destructor, void *state);

//  *** Draft method, defined for internal use only ***
//  Empty certificate hashtable. This wrapper exists to be friendly to bindings,
//  which don't usually have access to struct internals.                        
CZMQ_EXPORT void
    zcertstore_empty (zcertstore_t *self);

//  *** Draft method, defined for internal use only ***
//  Return frame routing ID, if the frame came from a ZMQ_SERVER socket.
//  Else returns zero.                                                  
CZMQ_EXPORT uint32_t
    zframe_routing_id (zframe_t *self);

//  *** Draft method, defined for internal use only ***
//  Set routing ID on frame. This is used if/when the frame is sent to a
//  ZMQ_SERVER socket.                                                  
CZMQ_EXPORT void
    zframe_set_routing_id (zframe_t *self, uint32_t routing_id);

//  *** Draft method, defined for internal use only ***
//  Return frame group of radio-dish pattern.
CZMQ_EXPORT const char *
    zframe_group (zframe_t *self);

//  *** Draft method, defined for internal use only ***
//  Set group on frame. This is used if/when the frame is sent to a
//  ZMQ_RADIO socket.                                              
//  Return -1 on error, 0 on success.                              
CZMQ_EXPORT int
    zframe_set_group (zframe_t *self, const char *group);

//  *** Draft method, defined for internal use only ***
//  By default the reactor stops if the process receives a SIGINT or SIGTERM 
//  signal. This makes it impossible to shut-down message based architectures
//  like zactors. This method lets you switch off break handling. The default
//  nonstop setting is off (false).                                          
CZMQ_EXPORT void
    zloop_set_nonstop (zloop_t *self, bool nonstop);

//  *** Draft method, defined for internal use only ***
//  Return message routing ID, if the message came from a ZMQ_SERVER socket.
//  Else returns zero.                                                      
CZMQ_EXPORT uint32_t
    zmsg_routing_id (zmsg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set routing ID on message. This is used if/when the message is sent to a
//  ZMQ_SERVER socket.                                                      
CZMQ_EXPORT void
    zmsg_set_routing_id (zmsg_t *self, uint32_t routing_id);

//  *** Draft method, defined for internal use only ***
//  By default the poller stops if the process receives a SIGINT or SIGTERM  
//  signal. This makes it impossible to shut-down message based architectures
//  like zactors. This method lets you switch off break handling. The default
//  nonstop setting is off (false).                                          
CZMQ_EXPORT void
    zpoller_set_nonstop (zpoller_t *self, bool nonstop);

//  *** Draft method, defined for internal use only ***
//  Create a SERVER socket. Default action is bind.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_server (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Create a CLIENT socket. Default action is connect.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_client (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Create a RADIO socket. Default action is bind.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_radio (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Create a DISH socket. Default action is connect.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_dish (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Create a GATHER socket. Default action is bind.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_gather (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Create a SCATTER socket. Default action is connect.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zsock_t *
    zsock_new_scatter (const char *endpoint);

//  *** Draft method, defined for internal use only ***
//  Return socket routing ID if any. This returns 0 if the socket is not
//  of type ZMQ_SERVER or if no request was already received on it.     
CZMQ_EXPORT uint32_t
    zsock_routing_id (zsock_t *self);

//  *** Draft method, defined for internal use only ***
//  Set routing ID on socket. The socket MUST be of type ZMQ_SERVER.        
//  This will be used when sending messages on the socket via the zsock API.
CZMQ_EXPORT void
    zsock_set_routing_id (zsock_t *self, uint32_t routing_id);

//  *** Draft method, defined for internal use only ***
//  Join a group for the RADIO-DISH pattern. Call only on ZMQ_DISH.
//  Returns 0 if OK, -1 if failed.                                 
CZMQ_EXPORT int
    zsock_join (void *self, const char *group);

//  *** Draft method, defined for internal use only ***
//  Leave a group for the RADIO-DISH pattern. Call only on ZMQ_DISH.
//  Returns 0 if OK, -1 if failed.                                  
CZMQ_EXPORT int
    zsock_leave (void *self, const char *group);

//  *** Draft method, defined for internal use only ***
//  Get socket option `heartbeat_ivl`.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT int
    zsock_heartbeat_ivl (void *self);

//  *** Draft method, defined for internal use only ***
//  Set socket option `heartbeat_ivl`.
CZMQ_EXPORT void
    zsock_set_heartbeat_ivl (void *self, int heartbeat_ivl);

//  *** Draft method, defined for internal use only ***
//  Get socket option `heartbeat_ttl`.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT int
    zsock_heartbeat_ttl (void *self);

//  *** Draft method, defined for internal use only ***
//  Set socket option `heartbeat_ttl`.
CZMQ_EXPORT void
    zsock_set_heartbeat_ttl (void *self, int heartbeat_ttl);

//  *** Draft method, defined for internal use only ***
//  Get socket option `heartbeat_timeout`.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT int
    zsock_heartbeat_timeout (void *self);

//  *** Draft method, defined for internal use only ***
//  Set socket option `heartbeat_timeout`.
CZMQ_EXPORT void
    zsock_set_heartbeat_timeout (void *self, int heartbeat_timeout);

//  *** Draft method, defined for internal use only ***
//  Get socket option `use_fd`.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT int
    zsock_use_fd (void *self);

//  *** Draft method, defined for internal use only ***
//  Set socket option `use_fd`.
CZMQ_EXPORT void
    zsock_set_use_fd (void *self, int use_fd);

//  *** Draft method, defined for internal use only ***
//  Accepts a void pointer and returns a fresh character string. If source
//  is null, returns an empty string.                                     
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT char *
    zstr_str (void *source);

//  *** Draft constants, defined for internal use only ***
#define ZGOSSIP_MSG_HELLO 1                 // 
#define ZGOSSIP_MSG_PUBLISH 2               // 
#define ZGOSSIP_MSG_PING 3                  // 
#define ZGOSSIP_MSG_PONG 4                  // 
#define ZGOSSIP_MSG_INVALID 5               // 

//  *** Draft method, defined for internal use only ***
//  Create a new empty zgossip_msg
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zgossip_msg_t *
    zgossip_msg_new (void);

//  *** Draft method, defined for internal use only ***
//  Destroy a zgossip_msg instance
CZMQ_EXPORT void
    zgossip_msg_destroy (zgossip_msg_t **self_p);

//  *** Draft method, defined for internal use only ***
//  Receive a zgossip_msg from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.   
CZMQ_EXPORT int
    zgossip_msg_recv (zgossip_msg_t *self, zsock_t *input);

//  *** Draft method, defined for internal use only ***
//  Send the zgossip_msg to the output socket, does not destroy it
CZMQ_EXPORT int
    zgossip_msg_send (zgossip_msg_t *self, zsock_t *output);

//  *** Draft method, defined for internal use only ***
//  Print contents of message to stdout
CZMQ_EXPORT void
    zgossip_msg_print (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Get the message routing id, as a frame
CZMQ_EXPORT zframe_t *
    zgossip_msg_routing_id (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set the message routing id from a frame
CZMQ_EXPORT void
    zgossip_msg_set_routing_id (zgossip_msg_t *self, zframe_t *routing_id);

//  *** Draft method, defined for internal use only ***
//  Get the zgossip_msg message id
CZMQ_EXPORT int
    zgossip_msg_id (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set the zgossip_msg message id
CZMQ_EXPORT void
    zgossip_msg_set_id (zgossip_msg_t *self, int id);

//  *** Draft method, defined for internal use only ***
//  Get the zgossip_msg message id as printable text
CZMQ_EXPORT const char *
    zgossip_msg_command (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Get the key field
CZMQ_EXPORT const char *
    zgossip_msg_key (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set the key field
CZMQ_EXPORT void
    zgossip_msg_set_key (zgossip_msg_t *self, const char *key);

//  *** Draft method, defined for internal use only ***
//  Get the value field
CZMQ_EXPORT const char *
    zgossip_msg_value (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set the value field
CZMQ_EXPORT void
    zgossip_msg_set_value (zgossip_msg_t *self, const char *value);

//  *** Draft method, defined for internal use only ***
//  Get the ttl field
CZMQ_EXPORT uint32_t
    zgossip_msg_ttl (zgossip_msg_t *self);

//  *** Draft method, defined for internal use only ***
//  Set the ttl field
CZMQ_EXPORT void
    zgossip_msg_set_ttl (zgossip_msg_t *self, uint32_t ttl);

//  *** Draft method, defined for internal use only ***
//  Self test of this class.
CZMQ_EXPORT void
    zgossip_msg_test (bool verbose);

#endif // CZMQ_BUILD_DRAFT_API

#endif
