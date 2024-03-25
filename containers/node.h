#pragma once
template <typename T>
struct Node {
  Node(T value_) : value(value_), next(nullptr){};
  T value;
  Node* next;
};
template <typename T>
struct ListNode {
  ListNode(T value_) : value(value_), next(nullptr), prev(nullptr){};
  T value;
  ListNode* next;
  ListNode* prev;
};