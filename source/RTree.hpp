// Copyright

#ifndef SOURCE_RTREE_HPP_
#define SOURCE_RTREE_HPP_

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

#include "Rectangle.hpp"

template <size_t N, typename ElemType, size_t M, size_t m = M / 2>
class RTree {
 public:
  struct Node;

  struct SpatialObject {
    Rectangle<N> box;
    ElemType identifier;
    std::shared_ptr<Node> child_pointer;
  };

  struct Node {
    typedef SpatialObject *iterator;
    typedef const SpatialObject *const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    SpatialObject &operator[](size_t index);
    SpatialObject operator[](size_t index) const;

    bool is_leaf();
    // std::shared_ptr<Node> insert(const Rectangle<N> &box,
    //                              const ElemType &identifier,
    //                              const std::shared_ptr<Node> &child_pointer);

    std::shared_ptr<Node> insert(SpatialObject new_entry);

    SpatialObject entry[M];
    size_t size = 0;
  };

  RTree();
  virtual ~RTree();
  size_t dimension() const;
  size_t size() const;
  bool empty() const;

  void insert(const Rectangle<N> &box, const ElemType &value);
  std::shared_ptr<Node> choose_leaf(const std::shared_ptr<Node> &current_node,
                                    const Rectangle<N> &box,
                                    const ElemType &value);

  std::shared_ptr<Node> choose_node(const std::shared_ptr<Node> &current_node,
                                    const Rectangle<N> &box,
                                    SpatialObject *entry);

  std::shared_ptr<Node> adjust_tree(const std::shared_ptr<Node> &parent,
                                    const std::shared_ptr<Node> &left,
                                    const std::shared_ptr<Node> &right,
                                    SpatialObject *entry);

  std::vector<ElemType> &operator[](const Rectangle<N> &box);
  std::vector<ElemType> &at(const Rectangle<N> &box);
  const std::vector<ElemType> &at(const Rectangle<N> &box) const;
  // std::vector<ElemType> kNNValue(const Rectangle<N> &box, size_t k) const;

  // private:
  std::shared_ptr<Node> root_pointer_;
};

/** Node R-tree struct implementation details*/
template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::Node::iterator
RTree<N, ElemType, M, m>::Node::begin() {
  return entry;
}

template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::Node::iterator
RTree<N, ElemType, M, m>::Node::end() {
  return entry + size;
}

template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::Node::const_iterator
RTree<N, ElemType, M, m>::Node::begin() const {
  return entry;
}

template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::Node::const_iterator
RTree<N, ElemType, M, m>::Node::end() const {
  return entry + size;
}

template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::SpatialObject
    &RTree<N, ElemType, M, m>::Node::operator[](size_t index) {
  return entry[index];
}

template <size_t N, typename ElemType, size_t M, size_t m>
typename RTree<N, ElemType, M, m>::SpatialObject
    RTree<N, ElemType, M, m>::Node::operator[](size_t index) const {
  return entry[index];
}

template <size_t N, typename ElemType, size_t M, size_t m>
bool RTree<N, ElemType, M, m>::Node::is_leaf() {
  if (size && entry[0].child_pointer) {
    return false;
  }
  return true;
}

template <size_t N, typename ElemType, size_t M, size_t m>
std::shared_ptr<typename RTree<N, ElemType, M, m>::Node>
RTree<N, ElemType, M, m>::Node::insert(SpatialObject new_entry) {
  return nullptr;
}

/** R-Tree class implementation details */

template <size_t N, typename ElemType, size_t M, size_t m>
RTree<N, ElemType, M, m>::RTree() : root_pointer_(new Node) {}

template <size_t N, typename ElemType, size_t M, size_t m>
RTree<N, ElemType, M, m>::~RTree() {}

template <size_t N, typename ElemType, size_t M, size_t m>
size_t RTree<N, ElemType, M, m>::dimension() const {
  return size_t(0);
}

template <size_t N, typename ElemType, size_t M, size_t m>
size_t RTree<N, ElemType, M, m>::size() const {
  return size_t(0);
}

template <size_t N, typename ElemType, size_t M, size_t m>
bool RTree<N, ElemType, M, m>::empty() const {
  return false;
}

template <size_t N, typename ElemType, size_t M, size_t m>
void RTree<N, ElemType, M, m>::insert(const Rectangle<N> &box,
                                      const ElemType &value) {
  return;
}

template <size_t N, typename ElemType, size_t M, size_t m>
std::shared_ptr<typename RTree<N, ElemType, M, m>::Node>
RTree<N, ElemType, M, m>::choose_leaf(const std::shared_ptr<Node> &current_node,
                                      const Rectangle<N> &box,
                                      const ElemType &value) {
  return nullptr;
}

template <size_t N, typename ElemType, size_t M, size_t m>
std::shared_ptr<typename RTree<N, ElemType, M, m>::Node>
RTree<N, ElemType, M, m>::choose_node(const std::shared_ptr<Node> &current_node,
                                      const Rectangle<N> &box,
                                      SpatialObject *entry) {
  return nullptr;
}

template <size_t N, typename ElemType, size_t M, size_t m>
std::shared_ptr<typename RTree<N, ElemType, M, m>::Node>
RTree<N, ElemType, M, m>::adjust_tree(const std::shared_ptr<Node> &parent,
                                      const std::shared_ptr<Node> &left,
                                      const std::shared_ptr<Node> &right,
                                      SpatialObject *entry) {
  return nullptr;
}

#endif  // SOURCE_RTREE_HPP_
