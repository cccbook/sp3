#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "setting.h"

int main() {
    
    PGconn *conn = PQconnectdb(connectStr);

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    }

    PGresult *res = PQexec(conn, "BEGIN");    
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {

        printf("BEGIN command failed\n");        
        PQclear(res);
        do_exit(conn);
    }    
    
    PQclear(res);   
    
    res = PQexec(conn, "UPDATE Cars SET Price=23700 WHERE Id=8");    
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {

        printf("UPDATE command failed\n");        
        PQclear(res);
        do_exit(conn);
    }    
    
    res = PQexec(conn, "INSERT INTO Cars VALUES(10,'XMazda',27790)");    
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {

        printf("INSERT command failed\n");        
        PQclear(res);
        do_exit(conn);
    }       
    
    res = PQexec(conn, "COMMIT"); 
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {

        printf("COMMIT command failed\n");        
        PQclear(res);
        do_exit(conn);
    }       
    
    PQclear(res);      
    PQfinish(conn);
    printf("pqtransact (UPDATE/INSERT/COMMIT) success!");
    return 0;
}
