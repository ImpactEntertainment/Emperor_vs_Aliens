/**
 * \file imageset.h
 * \brief Interface que representa um conjunto de imagens.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 29/01/2012
 */
#ifndef IMAGE_SET_H
#define	IMAGE_SET_H

#include <vector>
#include "image.h"

using namespace std;

namespace edge {
	
	class ImageSet {
	public:
		ImageSet();
		~ImageSet();
		
        static ImageSet * load(const string& imagePath, int imagesCount) 
			throw (Exception);
        
		void addImage(Image *image);
		int size() const;
		Image * image(int index) const;
		
	private:
		vector<Image *> images;
	};
}

#endif

