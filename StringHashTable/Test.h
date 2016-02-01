//
//  Test.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__Test__
#define __StringHashTable__Test__

#include "includes.h"
#include "StringHashTable.h"
#include "JMyStack.h"
#include "LinearProbHashTable.h"
#include "Myqueue.h"
#include "MyHeap.h"
#include "MySegmentTree.h"
#include "TopologicalSort.h"


class Test{
public:
    static void testHashTable();
    static void testJMyStack();
    static void testLinearProbHashTable();
    //static void testMyqueue();
    static void testMyHeap();
    static void testMySegmentTree();
    static void testMyTopologicalSort();
};
#endif /* defined(__StringHashTable__Test__) */
