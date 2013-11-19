// cardnames.c
// Lists the names of all ALSA sound cards in the system.
//
// Compile as:
// gcc -o cardnames cardnames.c -lasound

#include <stdio.h>
#include <string.h>
#include <alsa/asoundlib.h>

int main(int argc, char **argv)
{
    register int  err;
    int           cardNum;

    // Start with first card
    cardNum = -1;

    for (;;)
    {
        snd_ctl_t *cardHandle;

        // Get next sound card's card number. When "cardNum" == -1, then ALSA
        // fetches the first card
        if ((err = snd_card_next(&cardNum)) < 0)
        {
            printf("Can't get the next card number: %s\n", snd_strerror(err));
            break;
        }

        // No more cards? ALSA sets "cardNum" to -1 if so
        if (cardNum < 0) break;

        // Open this card's control interface. We specify only the card number -- not
        // any device nor sub-device too
        {
            char   str[64];

            sprintf(str, "hw:%i", cardNum);
            if ((err = snd_ctl_open(&cardHandle, str, 0)) < 0)
            {
                printf("Can't open card %i: %s\n", cardNum, snd_strerror(err));
                continue;
            }
        }

        {
            snd_ctl_card_info_t *cardInfo;

            // We need to get a snd_ctl_card_info_t. Just alloc it on the stack
            snd_ctl_card_info_alloca(&cardInfo);

            // Tell ALSA to fill in our snd_ctl_card_info_t with info about this card
            if ((err = snd_ctl_card_info(cardHandle, cardInfo)) < 0)
                printf("Can't get info for card %i: %s\n", cardNum, snd_strerror(err));
            else
                printf("Card %i = %s\n", cardNum, snd_ctl_card_info_get_name(cardInfo));
        }

        // Close the card's control interface after we're done with it
        snd_ctl_close(cardHandle);
    }

    // ALSA allocates some mem to load its config file when we call some of the
    // above functions. Now that we're done getting the info, let's tell ALSA
    // to unload the info and free up that mem
    snd_config_update_free_global();
}
