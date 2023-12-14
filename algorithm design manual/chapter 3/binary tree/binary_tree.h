#pragma once

template <typename T>
class Tree{
    T item;
    Tree * parent;
    Tree * left;
    Tree * right;
};