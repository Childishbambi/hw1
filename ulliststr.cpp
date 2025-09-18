#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val) {
  if(tail_ == NULL){
    Item* newPtr = new Item;
    newPtr->val[0] = val;
    newPtr->last = 1;
    newPtr->next = NULL;
    tail_ = newPtr;
    size_ += 1;
  } else if (tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
    size_ += 1;
  } else {
    Item* newPtr = new Item;
    newPtr->val[0] = val;
    newPtr->last = 1;
    newPtr->prev = tail_;
    newPtr->next = NULL;
    tail_ = newPtr;
    size_ += 1;
  }

}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  if(tail_ != NULL){
    size_ -= 1;
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    tail_->last -= 1;
    delete temp;
  } else if (tail_->prev != NULL) {
    size_ -= 1;
    Item* temp = tail_->prev;
    tail_ = tail_->prev;
    tail_->next = NULL;
    tail_->last -= 1;
    delete temp;
  }
}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){
    Item* newPtr = new Item;
    newPtr->val[0] = val;
    newPtr->prev = NULL;
    head_ = newPtr;
    size_ += 1;
  } else if (head_ -> last < ARRSIZE){
    head_->val[head_->first] = val;
    if(head_->first != 0) {
      head_->first -= 1;
    }
    size_ += 1;
  } else {
    Item* newPtr = new Item;
    newPtr->val[ARRSIZE - 1] = val;
    newPtr->first = ARRSIZE - 1;
    newPtr->prev = NULL;
    newPtr->next = head_;
    head_ = newPtr;
    size_ += 1;
  }
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  if(head_ != NULL){
    size_ -= 1;
    Item* temp = head_;
    head_ = head_->next;
    head_->prev = NULL;

    if(head_->first != 0){
      head_->first += 1;
    }

    delete temp;
  } else if (head_->next != NULL){
    size_ -= 1;
    Item* temp = head_->next;
    head_ = head_->next;
    head_->prev = NULL;
    head_->first = 0;
    delete temp;
  }

}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const& ULListStr::back() const{
  if(tail_ == NULL){
    return NULL;
  } else {
    return tail_->val[tail_->last - 1];
  }
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const& ULListStr::front() const{
  if(head_ == NULL){
    return NULL;
  } else {
    return head_->val[head_->first];
  }
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  //Assuming Recursion is not a requirement
  if(loc >= size_){
    return NULL;
  } 

  Item* curr = head_;
  while((curr->last - curr->first) <= loc){
    loc -= curr->last - curr->first;
    curr = curr->next;
  }
  return &curr->val[curr->first + loc];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
