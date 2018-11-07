/*
 * Review.cpp
 *
 *  Created on: 07/11/2018
 *      Author: josem
 */

#include "Review.h"
#include <string>

Review::Review(int rate,string review)
{
    this->rate = rate;
    this->review = review;
}

Review::~Review() {
	// TODO Auto-generated destructor stub
}

