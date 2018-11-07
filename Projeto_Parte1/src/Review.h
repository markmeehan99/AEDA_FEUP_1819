/*
 * Review.h
 *
 *  Created on: 07/11/2018
 *      Author: josem
 */

#ifndef REVIEW_H_
#define REVIEW_H_

#include <string>

using namespace std;

class Review {
	int rate;
	string review;

public:
	Review(int rate, string review);
	virtual ~Review();
};

#endif /* REVIEW_H_ */
