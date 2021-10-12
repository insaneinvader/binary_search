#include <stdio.h>

static int find_naive(const int * tab_ptr, int tab_cnt, int val_to_find)
{
    if (NULL == tab_ptr) return -1;

    // continue to compare with each array item until value is found
    for (int id = 0; id < tab_cnt; ++id)
    {
        if (tab_ptr[id] == val_to_find)
        {
            return id;
        }
    }
    
    return -1;
}

static int find_in_sorted(const int * tab_ptr, int tab_cnt, int val_to_find)
{
    if (NULL == tab_ptr) return -1;
    if (0 == tab_cnt) return -1;

    int id_first = 0;
    int id_last = tab_cnt - 1;

    // continue to split array until value is found
    do
    {
        int id_mid = id_first + (id_last - id_first) / 2;
        int val_at_mid = tab_ptr[id_mid];
        if (val_to_find < val_at_mid)
        {
            id_last = id_mid - 1;  // somewhere in left half
        }
        else if (val_to_find > val_at_mid)
        {
            id_first = id_mid + 1; // somewhere in right half
        }
        else // val_to_find == val_at_mid
        {
            return id_mid;        // exactly here between halves
        }
    }
    while (id_first <= id_last);

    return -1;
}

int main()
{
    int test_arr[] = {1, 5, 6, 11, 15, 17, 18, 21, 24, 33, 54, 72, 81, 85, 99};
    int test_cnt = sizeof(test_arr) / sizeof(test_arr[0]);

    int test_val_min = test_arr[0] - 1;
    int test_val_max = test_arr[test_cnt - 1] + 1;

    for (int test_val = test_val_min; test_val <= test_val_max; ++test_val)
    {
        int id_naive  = find_naive    (test_arr, test_cnt, test_val);
        int id_sorted = find_in_sorted(test_arr, test_cnt, test_val);

        const char * test_res = (id_naive == id_sorted) ? "OK" : "FAIL";

        printf("test_val = %3i, id_naive = [%2i], id_sorted = [%2i], %s\n",
            test_val, id_naive, id_sorted, test_res);
    }

    return 0;
}
