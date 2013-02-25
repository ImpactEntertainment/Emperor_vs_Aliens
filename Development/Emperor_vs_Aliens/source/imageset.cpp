#include <vector>
#include <iostream>

#include "imageset.h"

namespace edge {

	ImageSet::ImageSet()
	{

	}

	ImageSet::~ImageSet()
	{
		int imagesCount = images.size();

		for (int i = 0; i < imagesCount; i++) {
			if (images[i]) {
				delete images[i];
			}
		}
	}

	ImageSet *
	ImageSet::load(const string& imagePath, int imagesCount) throw(Exception)
	{
		if (imagesCount < 1) {
			imagesCount = 1;
		}

		Image *base = Image::load(imagePath);
		ImageSet *set = new ImageSet();

		if (base == NULL) {
			return NULL;
		}

		int imagesWidth = base->width() / imagesCount;
		Image *image;
		Point position(0, 0);
		Rectangle rect;

		rect.width = imagesWidth;
		rect.height = base->height();

		for (int i = 0; i < imagesCount; i++) {
			image = base->select(position, rect);

			set->addImage(image);
			position.x += imagesWidth;
		}

		return set;
	}

	void
	ImageSet::addImage(Image* image)
	{
		images.push_back(image);
	}

	int
	ImageSet::size() const
	{
		return images.size();
	}

	Image *
	ImageSet::image(int index) const
	{
		if (index >= 0 && index < (int) images.size()) {
			return images[index];
		} else
			return NULL;
	}
	
}