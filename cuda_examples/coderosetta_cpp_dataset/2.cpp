static void update_global_node_set(site_def *site) {
    u_int i;
    u_int nodes = get_maxnodes(site);
    node_no count = 0;
    for (i = 0; i < nodes && i < site->global_node_set.node_set_len; i++) {
        site->global_node_set.node_set_val[i] = DETECT(site);
    }
}