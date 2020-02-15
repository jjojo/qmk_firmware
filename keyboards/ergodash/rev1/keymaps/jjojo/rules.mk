BACKLIGHT_ENABLE = no

# Enable RGB underglow
# https://beta.docs.qmk.fm/features/feature_rgblight
RGBLIGHT_ENABLE = yes # +5500 bytes
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC	 += rgb.c
endif

AUDIO_ENABLE = no
NKRO_ENABLE = yes
STENO_ENABLE = yes
KEY_LOCK_ENABLE = yes
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = yes
