#ifndef NEC_MODULE_H_
#define NEC_MODULE_H_

#include "general_util.h"
#include "ir_types.h"
#include "errors.h"

#include <stdbool.h>
#include <stdint.h>

bool is_nec_header(struct Segment header_segments[]);
bool is_nec_repeat_header(struct Segment header_segments[]);
int8_t nec_data_bit_from_pair(struct Pair mark_and_space);

#endif /* NEC_MODULE_H_ */