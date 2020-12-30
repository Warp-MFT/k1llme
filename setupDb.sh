#!/bin/bash

WORK_DIR=$PWD
SQL_SCRIPT=$WORK_DIR/database.sql
DB_HOST=127.0.0.1
DB_PORT=5432
DB_USER_ADMIN=postgres
DB_PASSWORD=postgres

function loadSqlScript
{
    sudo PGPASSWORD=$1 psql -h $2 -U $3 -p $4 -a -q -f $5
}

function removeSqlScript
{
    sudo PGPASSWORD=$1 psql -h $2 -U $3 -p $4 -d postgres -a -q -c "drop database my_db;"
}

function setupDataBase
{
    sudo -u $DB_USER_ADMIN psql -U $DB_USER_ADMIN -c "alter user postgres with password '$DB_PASSWORD';"
    loadSqlScript $DB_PASSWORD $DB_HOST $DB_USER_ADMIN $DB_PORT $SQL_SCRIPT
    cd $WORK_DIR
}

function removeDataBase
{
    removeSqlScript $DB_PASSWORD $DB_HOST $DB_USER_ADMIN $DB_PORT
}
