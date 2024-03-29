#ifndef IR_UTIL_H_
#define IR_UTIL_H_

#include "ir_types.h"
#include "errors.h"
#include "nec_module.h"
#include <stdint.h>

bool all_data_bits_received(Protocol_Type protocol, uint8_t data_bit_counter);
int16_t get_bit_position(Protocol_Type protocol, uint8_t bit_counter);
Protocol_Type protocol_from_header(struct Segment header_segments[], uint8_t size);
void reinitialize_segment(struct Segment *segment);
void reinitialize_pair(struct Pair *pair);

#endif /* IR_UTIL_H_ */