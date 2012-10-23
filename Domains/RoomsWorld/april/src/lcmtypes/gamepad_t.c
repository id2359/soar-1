/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <string.h>
#include "gamepad_t.h"

static int __gamepad_t_hash_computed;
static int64_t __gamepad_t_hash;
 
int64_t __gamepad_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __gamepad_t_get_hash)
            return 0;
 
    const __lcm_hash_ptr cp = { p, (void*)__gamepad_t_get_hash };
    (void) cp;
 
    int64_t hash = 0x345b96879832ec32LL
         + __int64_t_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
        ;
 
    return (hash<<1) + ((hash>>63)&1);
}
 
int64_t __gamepad_t_get_hash(void)
{
    if (!__gamepad_t_hash_computed) {
        __gamepad_t_hash = __gamepad_t_hash_recursive(NULL);
        __gamepad_t_hash_computed = 1;
    }
 
    return __gamepad_t_hash;
}
 
int __gamepad_t_encode_array(void *buf, int offset, int maxlen, const gamepad_t *p, int elements)
{
    int pos = 0, thislen, element;
 
    for (element = 0; element < elements; element++) {
 
        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, &(p[element].present), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].naxes), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].axes, p[element].naxes);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].buttons), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
    }
    return pos;
}
 
int gamepad_t_encode(void *buf, int offset, int maxlen, const gamepad_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __gamepad_t_get_hash();
 
    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
 
    thislen = __gamepad_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;
 
    return pos;
}
 
int __gamepad_t_encoded_array_size(const gamepad_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {
 
        size += __int64_t_encoded_array_size(&(p[element].utime), 1);
 
        size += __boolean_encoded_array_size(&(p[element].present), 1);
 
        size += __int32_t_encoded_array_size(&(p[element].naxes), 1);
 
        size += __double_encoded_array_size(p[element].axes, p[element].naxes);
 
        size += __int64_t_encoded_array_size(&(p[element].buttons), 1);
 
    }
    return size;
}
 
int gamepad_t_encoded_size(const gamepad_t *p)
{
    return 8 + __gamepad_t_encoded_array_size(p, 1);
}
 
int __gamepad_t_decode_array(const void *buf, int offset, int maxlen, gamepad_t *p, int elements)
{
    int pos = 0, thislen, element;
 
    for (element = 0; element < elements; element++) {
 
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, &(p[element].present), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].naxes), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
        p[element].axes = (double*) lcm_malloc(sizeof(double) * p[element].naxes);
        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].axes, p[element].naxes);
        if (thislen < 0) return thislen; else pos += thislen;
 
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].buttons), 1);
        if (thislen < 0) return thislen; else pos += thislen;
 
    }
    return pos;
}
 
int __gamepad_t_decode_array_cleanup(gamepad_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {
 
        __int64_t_decode_array_cleanup(&(p[element].utime), 1);
 
        __boolean_decode_array_cleanup(&(p[element].present), 1);
 
        __int32_t_decode_array_cleanup(&(p[element].naxes), 1);
 
        __double_decode_array_cleanup(p[element].axes, p[element].naxes);
        if (p[element].axes) free(p[element].axes);
 
        __int64_t_decode_array_cleanup(&(p[element].buttons), 1);
 
    }
    return 0;
}
 
int gamepad_t_decode(const void *buf, int offset, int maxlen, gamepad_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __gamepad_t_get_hash();
 
    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;
 
    thislen = __gamepad_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;
 
    return pos;
}
 
int gamepad_t_decode_cleanup(gamepad_t *p)
{
    return __gamepad_t_decode_array_cleanup(p, 1);
}
 
int __gamepad_t_clone_array(const gamepad_t *p, gamepad_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {
 
        __int64_t_clone_array(&(p[element].utime), &(q[element].utime), 1);
 
        __boolean_clone_array(&(p[element].present), &(q[element].present), 1);
 
        __int32_t_clone_array(&(p[element].naxes), &(q[element].naxes), 1);
 
        q[element].axes = (double*) lcm_malloc(sizeof(double) * q[element].naxes);
        __double_clone_array(p[element].axes, q[element].axes, p[element].naxes);
 
        __int64_t_clone_array(&(p[element].buttons), &(q[element].buttons), 1);
 
    }
    return 0;
}
 
gamepad_t *gamepad_t_copy(const gamepad_t *p)
{
    gamepad_t *q = (gamepad_t*) malloc(sizeof(gamepad_t));
    __gamepad_t_clone_array(p, q, 1);
    return q;
}
 
void gamepad_t_destroy(gamepad_t *p)
{
    __gamepad_t_decode_array_cleanup(p, 1);
    free(p);
}
 
int gamepad_t_publish(lcm_t *lc, const char *channel, const gamepad_t *p)
{
      int max_data_size = gamepad_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = gamepad_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _gamepad_t_subscription_t {
    gamepad_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void gamepad_t_handler_stub (const lcm_recv_buf_t *rbuf, 
                            const char *channel, void *userdata)
{
    int status;
    gamepad_t p;
    memset(&p, 0, sizeof(gamepad_t));
    status = gamepad_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding gamepad_t!!!\n", status);
        return;
    }

    gamepad_t_subscription_t *h = (gamepad_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    gamepad_t_decode_cleanup (&p);
}

gamepad_t_subscription_t* gamepad_t_subscribe (lcm_t *lcm, 
                    const char *channel, 
                    gamepad_t_handler_t f, void *userdata)
{
    gamepad_t_subscription_t *n = (gamepad_t_subscription_t*)
                       malloc(sizeof(gamepad_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel, 
                                 gamepad_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg gamepad_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int gamepad_t_subscription_set_queue_capacity (gamepad_t_subscription_t* subs, 
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int gamepad_t_unsubscribe(lcm_t *lcm, gamepad_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr, 
           "couldn't unsubscribe gamepad_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}
