#ifndef _NERD_H
#define _NERD_H

NAGIOS_BEGIN_DECL

/** Nerd subscription type */
struct nerd_subscription {
	int sd;
	struct nerd_channel *chan;
	char *format; /* requested format (macro string) for this subscription */
};

/*** Nagios Event Radio Dispatcher functions ***/
extern int nerd_init(void);
extern int nerd_mkchan(const char *name, const char *description, int (*handler)(int, void *), unsigned int callbacks);
extern int nerd_cancel_subscriber(int sd);
extern int nerd_get_channel_id(const char *chan_name);
extern objectlist *nerd_get_subscriptions(int chan_id);
extern int nerd_broadcast(unsigned int chan_id, void *buf, unsigned int len);

NAGIOS_END_DECL

#endif
