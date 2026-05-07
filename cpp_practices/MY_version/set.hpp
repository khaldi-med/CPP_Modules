#include <bag.hpp>
#include <searchable_bag.hpp>
#include <tree_bag.hpp>


class set {
  searchable_bag &bag;

  public:
  set(searchable_bag &bag);
  ~set();
  set(const set &other);
  set &operator=(const set &other);
  void insert(int val);
  void insert(int* arr, int size);
  void print() const;
  void clear();
  bool has(int val) const;
  searchable_bag &get_bag() const;
};
