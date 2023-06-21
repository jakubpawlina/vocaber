#include "scale_wx_bitmap.h"

wxBitmap scaleWxBitmap(const wxBitmap &originalBitmap, const wxSize &maxSize) {
    double scaleWidth = static_cast<double>(maxSize.GetWidth()) / originalBitmap.GetWidth();
    double scaleHeight = static_cast<double>(maxSize.GetHeight()) / originalBitmap.GetHeight();
    double scaleFactor = std::min(scaleWidth, scaleHeight);
    int scaledWidth = static_cast<int>(originalBitmap.GetWidth() * scaleFactor);
    int scaledHeight = static_cast<int>(originalBitmap.GetHeight() * scaleFactor);
    wxImage scaledImage = originalBitmap.ConvertToImage().Rescale(scaledWidth, scaledHeight, wxIMAGE_QUALITY_HIGH);
    return wxBitmap{scaledImage};
}
