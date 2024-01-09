#include<stdio.h>
#include<stdlib.h>
#include"link_list.h"

int main(int argc, char *argv[]){

        // Create a HEAD node for linked list
        PNODE HEAD = NULL;

        // Add some numbers to the list
        list_add(&HEAD, 1);
        list_add(&HEAD, 12);
        list_add(&HEAD, 1234);
        list_add(&HEAD, 2222);
        list_add(&HEAD, 3333);
        list_add(&HEAD, 4444);

        // Add some numbers to beginning
        list_add_at_beg(&HEAD, 100);
        list_add_at_beg(&HEAD, 1000);
        list_add_at_beg(&HEAD, 10000);
        list_add_at_end(&HEAD, 6666);
        list_add_at_end(&HEAD, 7777);
        print_list(&HEAD);

        // Delete some numbers from beginning and end
        list_delete_at_beg(&HEAD);
        list_delete_at_beg(&HEAD);
        list_delete_at_end(&HEAD);
        print_list(&HEAD);

        list_delete_at_end(&HEAD);
        list_delete_at_end(&HEAD);
        print_list(&HEAD);

        list_delete_by_key(&HEAD, 100);
        list_delete_by_key(&HEAD, 1234);
        list_delete_by_key(&HEAD, 3333);
        print_list(&HEAD);

        // Erase list
        list_delete(&HEAD);
        print_list(&HEAD);

        return 0;
}