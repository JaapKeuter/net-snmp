#ifndef SNMPTCPBASEDOMAIN_H
#define SNMPTCPBASEDOMAIN_H

#include <net-snmp/library/snmp_transport.h>

#ifdef __cplusplus
extern          "C" {
#endif

/*
 * Prototypes
 */
    int netsnmp_tcpbase_recv(netsnmp_transport *t, void *buf, int size,
                             void **opaque, int *olength);
    int netsnmp_tcpbase_send(netsnmp_transport *t, const void *buf, int size,
                             void **opaque, int *olength);
    int netsnmp_tcpbase_session_init(struct netsnmp_transport_s *transport,
                                     struct snmp_session *sess);
        
#ifdef __cplusplus
}
#endif

#endif /* SNMPTCPBASEDOMAIN_H */
