alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя—.,…!?: "


def encode(text, shift):
    result = []
    for char in text.lower():
        if char in alphabet:
            index = (alphabet.index(char) + shift) % len(alphabet)
            result.append(str(index + 1))
        else:
            result.append(char)
    return "-".join(result)


def decode(encoded_text, shift):
    result = []
    for code in encoded_text.split('-'):
        if code.isdigit():
            index = (int(code) - 1 - shift) % len(alphabet)
            result.append(alphabet[index])
        else:
            result.append(code)
    return "".join(result)


text = """Ткнул этот человек собачку свою в следы возле двери, сказал «пс» и отошёл. Понюхала собака воздух, повела по толпе глазом (народ, конечно, собрался) и вдруг к бабке Фёкле, с пятого номера, подходит и нюхает ей подол. Бабка за толпу. Собака за юбку. Бабка в сторону — и собака за ней. Ухватила бабку за юбку и не пущает.
Рухнула бабка на колени перед агентом.
— Да,— говорит,— попалась. Не отпираюсь. И,— говорит,— пять ведёр закваски — это так. И аппарат — это действительно верно. Всё,— говорит,— находится в ванной комнате. Ведите меня в милицию.
Ну, народ, конечно, ахнул.
— А шуба? — спрашивают.
— Про шубу,— говорит,— ничего не знаю и ведать не ведаю, а остальное — это так. Ведите меня, казните.
Ну, увели бабку.
Снова взял агент собачищу свою, снова ткнул её носом в следы, сказал «пс» и отошёл.
Повела собачища глазом, понюхала пустой воздух и вдруг к гражданину управдому подходит."""
shift = 4

encoded_text = encode(text, shift)
print(encoded_text)

decoded_text = decode(encoded_text, shift)
print(decoded_text)
