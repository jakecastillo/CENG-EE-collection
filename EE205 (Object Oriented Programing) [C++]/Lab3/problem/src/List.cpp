#include ""../include/List.hpp"
#include ""../include/ListNode.hpp""
#include <utility>
#include <iostream>

List::List() {
     length = 0;
     head = nullptr;
}

List::List(const List& other) {
     ListNode *temp;
     ListNode *temp2;
     temp2 = temp;

     length = other.length;
     int data_temp;

     for(ListNode *iterator = other.head;iterator != nullptr; iterator=iterator->next) {
          data_temp = iterator->data;
          temp->next = new ListNode(data_temp);
          temp = temp->next;
     }

     temp->next = nullptr;
     head = temp2->next;
     delete[] temp2;
}

List::List(List&& other){
     head = other.head;
     length = other.length;

     other.head = nullptr;
     other.length = 0;
}

List::~List() {
     ListNode *temp = head;
     ListNode *temp2;

     while(temp != nullptr) {
          temp2 = temp;
          temp = temp->next;
          delete[] temp2;
     }
     head = nullptr;
     length = 0;
}

void List::append(int num) {
     if(length == 0) {
          head = new ListNode(num);
          head->next = nullptr;
     }

     else {
          ListNode *temp = head;
          ListNode *temp2;
          while(temp->next != nullptr) {
               temp = temp->next;
          }
          temp->next = new ListNode(num);
          temp->next->next = nullptr;
     }
     length = length + 1;
}

void List::insert(int index, int num) {
     if(index < 0 || index > length) {
          throw "Index out of bounds";
     }
     if(index == length) {
          append(num);
     }
     else {
          ListNode *iterate = head;
          for(int i = 0;i < index;i++) {
               iterate = iterate->next;
          }
          ListNode *temp = iterate->next;
          iterate->next = new ListNode(num);
          iterate->next->next = temp;
     
          length = length + 1;
     }
}

void List::remove(int index) {
     if(index < 0 || index >= length) {
          throw "Index out of bounds";
     }

     if(index == 0) {
          ListNode *temp = head->next;
          delete[] head;
          head = temp;
     }

     else {
           ListNode *iterate = head;
           for(int i = 0;i < (index-1);i++) {
                iterate = iterate->next;
           }
           ListNode *temp = iterate->next->next;
           delete[] iterate->next;
           iterate->next = temp;
     }
           length = length - 1;

int List::get(int index) const {
     if(index < 0 || index >= length) {
          throw "Index out of bounds";
     }

     ListNode *iterator = head;

     for(int i = 0;i <index;i++) {
          iterator = iterator->next;
     }

     return iterator->data;
}

std::size_t List::size() const {
     return length;
}

int& List::operator[](int index) {
     if(index < 0 || index >= length) {
          throw "Index out of bounds";
     }

     ListNode *iterator = head;

     for(int i = 0;i <index;i++) {
          iterator = iterator->next;
     }
     
     return iterator->data;
}

