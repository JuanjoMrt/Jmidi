#include "header/calderon.h"

Calderon::Calderon() {}

Calderon::Calderon(const Calderon & calderon) {
	this->calderon_image = calderon.calderon_image;
	this->begin_index = calderon.begin_index;
	this->end_index = calderon.end_index;
	this->num_rep = calderon.num_rep;
}

Calderon::Calderon(int begin, int end, int num_rep) {
	this->begin_index = begin;
	this->end_index = end;
	this->num_rep = num_rep;
}

Calderon::~Calderon() {}

bool Calderon::isCalderon() {
	return this->is_calderon;
}

int Calderon::countNotesInside() {
	return (end_index - begin_index)* num_rep;
}
