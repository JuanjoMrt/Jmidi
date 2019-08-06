#include "header/calderon.h"

Calderon::Calderon() {}

Calderon::Calderon(int begin, int end, int num_rep) {
	this->begin_index = begin;
	this->end_index = end;
	this->num_rep = num_rep;
}

Calderon::~Calderon() {}

bool Calderon::isCalderon() {
	return true;
}
