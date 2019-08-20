#include "header/calderon.h"

Calderon::Calderon() {}

Calderon::Calderon(int begin, int end, int num_rep) {
	this->begin_index = begin;
	this->end_index = end;
	this->num_rep = num_rep;
}

Calderon::Calderon(int begin, int end ,int ca, bool is_repetition) {
	this->begin_index = begin;
	this->end_index = end;
	this->ca = ca;
	this->num_rep = 1;
	this->is_repetition = is_repetition;
}

Calderon::~Calderon() {}

bool Calderon::isCalderon() {
	return this->is_calderon;
}

int Calderon::countNotesInside() {
	return (end_index - begin_index)* num_rep;
}

const bool Calderon::isRepetition() {
	return this->is_repetition;
}
