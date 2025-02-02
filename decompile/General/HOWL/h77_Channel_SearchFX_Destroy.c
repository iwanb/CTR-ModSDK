#include <common.h>

void Channel_DestroySelf(struct ChannelStats* stats);

// depending on flags, you might have:
//	16-bit soundID, which destroys all of this type of sound
//	32-bit soundID_count, which destroys specific instance of sound
struct ChannelStats* DECOMP_Channel_SearchFX_Destroy(
	int type, int soundID, int flags)
{	
	int backupNext;
	struct ChannelStats* curr;
		
	for(
			curr = sdata->channelTaken.first;
			curr != 0;
			curr = backupNext
		)
	{
		backupNext = curr->next;
		
		if(
			// matching type
			(curr->type == type) &&
		
			// matching ID and bit-shifted soundCount
			((curr->soundID & flags) == (soundID & flags))
		)
		{
			Channel_DestroySelf(curr);
			
			// OG code does this, but what if
			// there's multiple of the same sound?
			return curr;
		}
	}
	
	// sound not playing
	return 0;
}