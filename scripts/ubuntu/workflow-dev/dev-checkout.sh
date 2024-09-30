#!/bin/bash

. /usr/local/sbin/pdb-software-lib.sh

job_tasks=(
    "derivapy_pull_checkout"
    "derivaextras_pull_checkout"
    "pdb_www_pull_checkout"
    "derivapy_install"
    "derivaextras_install"
    "pdb_processing_install"
    "python_ihm_validation 412e6d0"
    "require service pdb_staging_processing_worker restart"
)

cron_run "hourly-update" "${job_tasks[@]}"

