#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_clear_screen = { 12 };

void vdp_clear_screen( void ) { VDP_PUTS( vdu_clear_screen ); }
