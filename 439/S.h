/*
 * =====================================================================================
 *
 *       Filename:  S.h
 *
 *    Description:  
 *
 *        Created:  08.11.2013 16:19:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#pragma once
#ifndef s_h
#define s_h
#include <omp.h>
#include <vector>
#include <set>
//#include <unistd.h>
#include "../GMPxx/BigInt.h"
//#include "d.h"
#include "../GMPxx/prime.hxx"

using namespace fleiamath;

BigInt* S(const BigInt N);
#endif
