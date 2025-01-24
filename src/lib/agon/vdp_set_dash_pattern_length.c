#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_set_dash_pattern_length = { 23, 0, 0xF2, 0 };

void vdp_set_dash_pattern_length( int n )
{
	if ( n > 64 ) return;

	vdu_set_dash_pattern_length.b0 = n;
	VDP_PUTS( vdu_set_dash_pattern_length );
}