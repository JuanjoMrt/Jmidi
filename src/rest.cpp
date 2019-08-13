#include "header/rest.h"

Rest::Rest() {}

Rest::~Rest() {}

qreal Rest::getX() {
	return this->rest_image->x();
}

int Rest::countNotesInside() {
	return duration;
}
