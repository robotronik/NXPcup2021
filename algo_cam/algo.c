
int frame[128];
int frame_filtered[128];
int outside_light = 50;
int track_light = 100;
int half_track_size = 50; // pixel



int algo(int frame[128]) {

	/* Filtrage */
	for (int k=2; k<126; k++) {
//			frame_filtered[k] = (int)((frame[k+2] + frame[k+1] - frame[k-1] - frame[k-2]) / 4); // derive avec lissage
		frame_filtered[k] = (frame[k+1] - frame[k-1])>>1; // derive
	}

	frame_filtered[1] = 0;
	frame_filtered[126] = 0;
	frame_filtered[0] = 0;
	frame_filtered[127] = 0;

	/* Détection primaire des pics */
	int min = 255, max = 0, pic_g, pic_d;
	for (int k = 0; k<64; k++) {
		if (frame_filtered[k] > max) {
			max = frame_filtered[k];
			pic_g = k;
		}
	}
	for (int k = 64; k<128; k++) {
		if (frame_filtered[k] < min) {
			min = frame_filtered[k];
			pic_d = k;
		}
	}

	/* Validation des pics */
	int pixel_ok, pos, pic_g_ok = 1, pic_d_ok = 1;
	int seuil = (int)((track_light - outside_light)/4); 

	/* Pic gauche */
	pos = pic_g - 3;
	pixel_ok = 0;
	if (pos > 5) {  //pourquoi 5 et pas 2 ? 
		for (int k = 0; k < 3; k++) {
			if (frame[pos-k] > outside_light - seuil && frame[pos-k] < outside_light + seuil) {
				pixel_ok++;
			}
		}
	}
	/* On rentre dans le if si on a validé la partie gauche du pic et on teste la partie droite du pic gauche */
	if (pixel_ok > 0) {
		pos = pic_g + 3;
		for (int k = 0; k < 3; k++) {
			if (frame[pos+k] > track_light - seuil && frame[pos+k] < track_light + seuil) {
				pixel_ok++;
			}
		}
	}
	/* inutile
	else {
		pic_g_ok = 0;
	}
	*/
	if (pixel_ok < 2) {
		pic_g_ok = 0;
	}

	/* Pic droit */
	/* On commence par vérifier la partie droite du pic droit */
	pos = pic_d + 3;
	pixel_ok = 0;
	if (pos < 124) {
		for (int k = 0; k < 3; k++) {
			if (frame[pos+k] > outside_light - seuil && frame[pos+k] < outside_light + seuil) { //out of bound si pos = 123
				pixel_ok++;
			}
		}
	}

	/* On rentre dans le if si on a validé la partie droite du pic droite et on teste la partie gauche du pic droit */
	if (pixel_ok > 0) {
		pos = pic_d - 3;
		for (int k = 0; k < 3; k++) {
			if (frame[pos-k] > track_light - seuil && frame[pos-k] < track_light + seuil) {
				pixel_ok++;
			}
		}
	}
	/* inutile
	else {
		pic_d_ok = 0;
	}*/
	if (pixel_ok < 2) {
		pic_d_ok = 0;
	}

	if (pic_d_ok && pic_g_ok) {
		track_middle = (pic_g + pic_d)>>1; //pas compris
		led_sel = 1;
	}

	else if (pic_g_ok) {
		track_middle = pic_g + half_track_size;
		led_sel = 0;
	}
	else if (pic_d_ok) {
		track_middle = pic_d - half_track_size;
		led_sel = 2;
	}
	else {
		track_middle = -1;
	}

    return track_middle;
}
