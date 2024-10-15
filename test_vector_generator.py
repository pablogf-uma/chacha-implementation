import json
from base64 import b64encode
from Crypto.Cipher import ChaCha20
from Crypto.Random import get_random_bytes

plaintext = '''Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean ligula tellus, interdum id rutrum in, ullamcorper vel sapien. Curabitur lacinia diam consequat metus scelerisque, a elementum turpis aliquet. Nullam facilisis massa non neque laoreet, at vestibulum risus hendrerit. Nam suscipit, enim eu maximus mattis, est risus molestie metus, eu venenatis ligula libero a purus. Vivamus justo justo, suscipit nec pulvinar ut, pharetra sodales sapien. Sed lacinia dapibus tempus. Cras nec est non sapien pretium tincidunt eget eu nisi. Nulla pharetra lectus quis consequat cursus. Nulla non aliquet eros, non aliquet odio. Praesent tincidunt purus risus, sed ultricies lacus rutrum non. Donec at ex vel velit feugiat tristique et interdum mauris.

Proin bibendum, est vestibulum lacinia fringilla, risus dolor bibendum tortor, nec finibus magna tortor sit amet mauris. Fusce gravida ultricies lectus in vestibulum. Fusce non risus mi. Maecenas in ligula tortor. Curabitur ultricies, lorem in mattis facilisis, neque mi luctus diam, in sollicitudin mauris risus eget leo. Nam ornare quam a ipsum consectetur aliquet. Ut sed diam bibendum eros vulputate faucibus. Maecenas convallis, diam sit amet sollicitudin vestibulum, velit mi facilisis dolor, ut semper nulla lorem sed ex.

Curabitur eget posuere diam. Proin non consequat mi, sed dignissim eros. Suspendisse ut ipsum vel elit euismod placerat sit amet quis lectus. Sed eget urna sed sapien ornare pharetra. Etiam placerat efficitur eros eu eleifend. Sed fringilla lorem ante, eget molestie tortor dignissim quis. Nam orci ipsum, viverra non dictum nec, posuere commodo nunc. Aliquam pretium eros ac ullamcorper lacinia. Fusce quis libero nec dolor semper semper. Cras eu dui consectetur, fermentum tortor sit amet, laoreet nulla. Suspendisse dictum purus eros. In hac habitasse platea dictumst. Vivamus fermentum finibus augue, quis facilisis orci mattis sed.

Phasellus nec convallis mi. Praesent sit amet tincidunt nisl, eget varius eros. Nulla eget sem risus. Praesent auctor varius orci id ornare. Nunc sodales et nunc a viverra. Suspendisse augue augue, scelerisque non blandit sit amet, dignissim eget diam. Donec dictum massa vel arcu posuere venenatis. Aenean a eros tempus, laoreet magna at, iaculis nisi. Nullam feugiat et augue ac blandit. Suspendisse id turpis mollis, rutrum enim vel, commodo mauris.

Nulla condimentum, augue eu auctor tristique, augue tortor ultricies dolor, nec tincidunt ante enim blandit purus. Integer porttitor magna at bibendum tristique. Pellentesque eu dolor dignissim, tincidunt nunc a, suscipit purus. Sed venenatis dignissim dignissim. Morbi eros sem, finibus ut blandit non, dictum sed est. Vestibulum velit nisl, aliquam nec lectus pharetra, semper volutpat neque. Mauris facilisis ultrices egestas. Mauris non rutrum justo. Donec et pharetra ipsum.

Sed aliquam, mauris nec posuere tempor, lectus eros mollis mi, eu mollis erat quam non odio. Quisque ipsum nunc, dictum vitae elit hendrerit, congue faucibus purus. Fusce at ligula ac nisi volutpat vulputate. Aenean mollis sit amet urna eu consectetur. In nec odio id nisi dictum auctor non non mi. Quisque sed odio ac lorem mattis tristique. Suspendisse velit nisl, finibus ac mattis sit amet, convallis ac urna.

In ultrices blandit sapien pellentesque mollis. Curabitur eget augue at lectus suscipit tincidunt sit amet ullamcorper leo. Curabitur vulputate, erat laoreet commodo aliquam, diam eros placerat eros, nec porttitor erat sapien a lorem. Nam scelerisque ut ipsum eu dictum. Sed at porta erat, ac sollicitudin lacus. Suspendisse nec porttitor dui. Praesent a imperdiet enim. Praesent pretium interdum arcu et fringilla. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Interdum et malesuada fames ac ante ipsum primis in faucibus.

Duis dapibus leo vitae est aliquet aliquam. Duis convallis faucibus nisi non posuere. Phasellus viverra risus vitae ligula blandit pharetra. Curabitur placerat egestas enim in sagittis. Sed scelerisque arcu at neque dignissim aliquet. Sed efficitur ornare neque quis cursus. Curabitur viverra mi arcu, quis rutrum eros mattis eget. Quisque euismod ligula ac justo bibendum, nec aliquam dolor pretium. Sed interdum rutrum est. Nam egestas leo neque, sit amet feugiat neque gravida eu.

Vivamus vel mi a massa vestibulum tristique vel eu enim. Vivamus iaculis vel massa sed iaculis. Maecenas rutrum faucibus erat, ornare vestibulum dui vestibulum vel. Nunc pulvinar metus eros, at tincidunt est efficitur ac. Pellentesque mauris magna, iaculis sit amet pharetra id, fringilla vitae nisl. Nam ex sem, aliquet a lorem porttitor, eleifend feugiat lorem. Vestibulum vestibulum massa ut ligula cursus finibus. Cras semper, dui ut suscipit tristique, elit orci hendrerit magna, ac posuere nisi nisl eget justo. Maecenas nisl lorem, commodo eu eros a, iaculis facilisis sem. Duis sodales eros ullamcorper sagittis tempor. Pellentesque suscipit lectus nibh, sit amet congue velit lacinia eu. Proin egestas ante ac odio nulla.'''

key = bytes([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01])
nonce = bytes([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
               0x00, 0x00, 0x00, 0x00])

print("\n Plaintext:\n")
print('{', end='')
for i in range(0, len(plaintext)):
    print('0x' + plaintext[i].encode().hex() + ', ', end='')
print('\b\b', end='')
print('}')
print()

cipher = ChaCha20.new(key=key, nonce=nonce)
cipher.seek(0)  # Ensure the counter is set to 0
ciphertext = cipher.encrypt(plaintext.encode())

print("\n Ciphertext:\n")
print('{', end='')
for i in range(0, len(ciphertext)):
    print('0x' + ciphertext[i:i+1].hex() + ', ', end='')
print('\b\b', end='')
print('}')
