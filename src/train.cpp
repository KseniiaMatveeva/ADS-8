// Copyright 2021 NNTU-CS
#include "train.h"
Train::Cage* Train::creatc(bool light) {
    Cage* cage = new Cage;
    cage -> light = light;
    cage -> next = nullptr;
    cage -> prev = nullptr;
    return cage;
}

void Train::addCage(bool light) {
  if (first->next == nullptr) {
    Cage* c = creatc(light);
    first->next = c;
    c->prev = first;
    c->next = first;
    first->prev = c;
  } else {
    if (first == nullptr) {
      first = creatc(light);
    }
    Cage* c = creatc(light);
    first->prev->next = c;
    c->next = first;
    c->prev = first->prev;
    first->prev = c;
  }
}

int Train::getLength() {
  Cage* f = first;
  first->light = true;
  countOp = 0;
  int len = 0;
  int zam = 0;
  while (first->light == true) {
    countOp++;
    len++;
    f = f->next;
    if (f->light == true) {
      f->light = false;
      zam = len;
      while (zam > 0) {
        f = f->prev;
        countOp++;
        zam--;
      }
      if (!(f->light)) {
        return len;
      }
    }
  }
  //return len;
}

int Train::getOpCount() {
    return countOp;
}
