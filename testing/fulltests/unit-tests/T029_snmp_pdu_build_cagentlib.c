/* HEADER snmp_pdu_build() */

static const uint8_t data[] = {
    0x20, 0x0e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20,
    0x5c, 0x00, 0x00, 0x00, 0x46, 0x00, 0x20, 0x20,
    0x0a, 0x00, 0x20, 0x20, 0x02, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0xff, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20,
    0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0xff,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
};

netsnmp_pdu *pdu = calloc(1, sizeof(*pdu));
netsnmp_session session = { .version = AGENTX_VERSION_1 };
agentx_parse(&session, pdu, NETSNMP_REMOVE_CONST(uint8_t *, data),
             sizeof(data));
oid name[] = { 2, 1, 0 };
size_t name_len = OID_LENGTH(name);
snmp_add_var(pdu, name, name_len, data[20], (const char *)data);
netsnmp_ds_set_boolean(*(const uint32_t *)&data[21],
                       *(const uint32_t *)&data[25],
                       *(const uint32_t *)&data[29]);
netsnmp_ds_set_boolean(NETSNMP_DS_LIBRARY_ID,
                       NETSNMP_DS_LIB_REVERSE_ENCODE,
                       *(const uint32_t *)&data[33]);
size_t build_out_length = 75;
uint8_t *encoded = malloc(build_out_length);
snmp_pdu_build(pdu, encoded, &build_out_length);
snmp_free_pdu(pdu);
free(encoded);
OK(1, "snmp_pdu_build()");