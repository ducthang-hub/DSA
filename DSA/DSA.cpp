#include <cstdio>
#include "String/c_string.h"
#include "Node/node.h"
#include "Tree/Binary Tree/binary_tree.h"
#include <windows.h>
#include "Tree/Binary Tree/leet_code.h"
#include "LinkedList/linked_list.h"
#include "General/kth_largest.h"
#include "Heap/MinHeap/min_heap.h"

const int number_of_char = 26;

using namespace std;

#pragma string_implement
void string_implement()
{
    char str[] = "IcEcrEAm";//12 chars
    
    // reverse a string
    // char *reversedString = c_string::reverse_string(str);
    
    // // check if a string is palindrome
    // bool palindrome = c_string::check_palindrome(str);
    
    // // check duplicated characters in a string
    // const int *duplicated_hash_table = c_string::check_duplicated(str);
    // string::print_duplicated_hash_table(duplicated_hash_table, number_of_char);
    // c_string::check_duplicated_bitwise(str);

    // string s = "abcd";
    // c_string::reverse_string_2k(s, 4);

    // c_string::reverse_words(str);

    // auto reversed_string = c_string::reverse_vowels(str);
    // printf("%s", reversed_string.c_str());

    c_string::can_construct("aa", "aab");
}

#pragma tree_implementation
static void print_bt(const std::string& prefix, const node* node, const bool is_left)
{
    SetConsoleOutputCP(CP_UTF8);
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (is_left ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        print_bt( prefix + (is_left ? "│   " : "    "), node->lchild, true);
        print_bt( prefix + (is_left ? "│   " : "    "), node->rchild, false);
    }
}
void tree_implementation()
{
    int a[7] = {10, 7, 6, 8, 14, 12, 15};
    const auto tree = new binary_tree;
    tree->create_tree_by_preorder(a, 7);
    print_bt("", tree->root, false);
}


#pragma linked_list_implementation
void linked_list_implementation()
{
    int data[] = {1,2,3,4,5,6,7};
    auto list = new linked_list(data, 7);
    list->reverse_by_sliding_pointer();
    list->print_linked_list();
}

#pragma
void heap_implementation()
{
    int *a = new int[]{3,2,1,5,6,4};
    int kth_largest = 3;
    min_heap *min_heap = new class min_heap(a, 9, kth_largest);
    min_heap->print();
    printf("%d largest: %d", kth_largest, min_heap->peek());
}

void test()
{
    vector<int> nums{4,5,8,2};
    kth_largest *kth_largest = new class kth_largest(nums, 3);
    printf("%d\n", kth_largest->add(3));
    printf("%d\n", kth_largest->add(5));
    printf("%d\n", kth_largest->add(10));
    printf("%d\n", kth_largest->add(9));
    printf("%d\n", kth_largest->add(4));
}

int main(int argc, char* argv[])
{
    test();
    // string_implement();
    // tree_implementation();
    // linked_list_implementation();
    // heap_implementation();
    
    return 0;
}
