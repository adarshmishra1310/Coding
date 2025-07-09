#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// X.find_by_order(k) return iterator of kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
template <typename T>
using _multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using _map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;