import qrcode

# Read the contents of the .txt file
with open('keytable.txt', 'r') as file:
    data = file.read()

# Create a QR code object
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)
qr.add_data(data)
qr.make(fit=True)

# Create an image from the QR code instance
img = qr.make_image(fill='black', back_color='white')

# Save the image
img.save('qrcode.png')
