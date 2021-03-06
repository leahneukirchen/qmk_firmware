/* Copyright 2015-2017 Jack Humbert
 * Copyright 2020 Leah Neukirchen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CAPS,  
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DHm
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/6|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |   -  |Lower |    Space    |   '  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,       KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
  LT(6,KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,  KC_G,   KC_M,   KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,  \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL,      KC_LGUI, KC_LALT, KC_MINS, MO(3), KC_SPC, KC_SPC, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Qwerty UNUSED
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/6|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |   -  |Lower |    Space    |   '  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  LT(6,KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL,      KC_LGUI, KC_LALT, KC_MINS, MO(3), KC_SPC, KC_SPC, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Dvorak UNUSED
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/6|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |   -  |Lower |    Space    |   /  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid( \
  KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,       KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
  LT(6,KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,  \
  KC_LSFT,      KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  KC_LCTL,      KC_LGUI, KC_LALT, KC_MINS, MO(3), KC_SPC, KC_SPC, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   =  |   +  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
 _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
 _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
 MO(_ADJUST), _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
 _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_EQL,  KC_PLUS, KC_MINS, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Raise UNUSED
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
 KC_GRV,  KC_1,    KC_2,   KC_3,     KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
 KC_GRV,  KC_1,    KC_2,   KC_3,     KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
 KC_DEL,  KC_F1,   KC_F2,  KC_F3,    KC_F4,   KC_F5,  KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
 _______, KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11, KC_F12,  KC_NUHS, KC_NUBS, KC_HOME, KC_END,  _______, \
 _______, _______, _______, _______, MO(_ADJUST), _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Adjust (Lower + Caps)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | QWE  | COL  | DVO  | RGB  |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
 _______, _______, _______, _______, _______, _______, _______, DF(_QWERTY), DF(_COLEMAK), DF(_DVORAK), RGB_TOG, RESET,  \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* QWERTY:
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX, XXXXXXX, XXXXXXX, A(KC_5), XXXXXXX, XXXXXXX, XXXXXXX, A(KC_Y), XXXXXXX, A(KC_O), XXXXXXX, XXXXXXX, \
 XXXXXXX, A(KC_Q), A(KC_S), KC_DEL,  KC_BSPC, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
*/

/* Capslock (needs us-intl activated)
 * ,-----------------------------------------------------------------------------------.
 * |  ^   | Mute | Vol- | Vol+ | F24  | Bri- | Bri+ |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  ü   |      |  °   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ä   |      |  ß   | Bksp |      |      |      |  €   |      |  ö   |  Ins |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Print |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
#define Z(x) (RALT(x))
#define KC_MMUT 111 /* mic mute on T480 */
[_CAPS] = LAYOUT_preonic_grid( \
 KC_CIRC, KC_MUTE, KC_VOLD, KC_VOLU, KC_MMUT, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, Z(KC_Y), XXXXXXX, Z(S(KC_SCLN)), KC_DEL, \
 XXXXXXX, Z(KC_Q), XXXXXXX, Z(KC_S), KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, Z(KC_5), XXXXXXX, Z(KC_P), KC_INS,  \
 XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        case QWERTY:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_QWERTY);
		}
		return false;
		break;
        case COLEMAK:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_COLEMAK);
		}
		return false;
		break;
        case DVORAK:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_DVORAK);
		}
		return false;
		break;
        case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
        case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
        case BACKLIT:
		if (record->event.pressed) {
			register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
			backlight_step();
#endif
#ifdef __AVR__
			writePinLow(E6);
#endif
		} else {
			unregister_code(KC_RSFT);
#ifdef __AVR__
			writePinHigh(E6);
#endif
		}
		return false;
		break;
	}
	return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
	if (muse_mode) {
		if (IS_LAYER_ON(_RAISE)) {
			if (clockwise) {
				muse_offset++;
			} else {
				muse_offset--;
			}
		} else {
			if (clockwise) {
				muse_tempo+=1;
			} else {
				muse_tempo-=1;
			}
		}
	} else {
		if (clockwise) {
			register_code(KC_PGDN);
			unregister_code(KC_PGDN);
		} else {
			register_code(KC_PGUP);
			unregister_code(KC_PGUP);
		}
	}
}

void dip_switch_update_user(uint8_t index, bool active) {
	switch (index) {
        case 0:
		if (active) {
			layer_on(_ADJUST);
		} else {
			layer_off(_ADJUST);
		}
		break;
        case 1:
		if (active) {
			muse_mode = true;
		} else {
			muse_mode = false;
		}
	}
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
	if (muse_mode) {
		if (muse_counter == 0) {
			uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
			if (muse_note != last_muse_note) {
				stop_note(compute_freq_for_midi_note(last_muse_note));
				play_note(compute_freq_for_midi_note(muse_note), 0xF);
				last_muse_note = muse_note;
			}
		}
		muse_counter = (muse_counter + 1) % muse_tempo;
	} else {
		if (muse_counter) {
			stop_all_notes();
			muse_counter = 0;
		}
	}
#endif
}

bool music_mask_user(uint16_t keycode) {
	switch (keycode) {
	case RAISE:
	case LOWER:
		return false;
	default:
		return true;
	}
}
