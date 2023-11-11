from heapq import heappush, heappop
from collections import defaultdict


class HuffmanNode:
    def __init__(self, char=None, freq=0, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

    def __str__(self):
        return str(self.char)

    def __repr__(self):
        return f"HuffmanNode({self.char}, {self.freq}, {self.left}, {self.right})"


def build_frequency_table(text):
    # Создаем таблицу частот для каждого символа в тексте
    frequency_table = defaultdict(int)
    for char in text:
        frequency_table[char] += 1
    return frequency_table


def build_huffman_tree(frequency_table):
    # Строим дерево Хаффмана на основе таблицы частот
    heap = []
    for char, freq in frequency_table.items():
        node = HuffmanNode(char, freq)
        heappush(heap, node)

    while len(heap) > 1:
        # Объединяем два узла с наименьшей частотой и создаем родительский узел
        left_node = heappop(heap)
        right_node = heappop(heap)
        parent_node = HuffmanNode(
            freq=left_node.freq + right_node.freq, left=left_node, right=right_node
        )
        heappush(heap, parent_node)
    return heap[0]


def build_encoding_table(huffman_tree):
    # Создаем таблицу кодирования на основе дерева Хаффмана
    encoding_table = {}

    def traverse(node, code):
        if node.char:
            encoding_table[node.char] = code
        else:
            traverse(node.left, code + "0")
            traverse(node.right, code + "1")

    traverse(huffman_tree, "")
    return encoding_table


def encode_text(text, encoding_table):
    # Кодируем текст с использованием таблицы кодирования
    encoded_text = ""
    for char in text:
        encoded_text += encoding_table[char]
    return encoded_text


def decode_text(encoded_text, huffman_tree):
    # Декодируем закодированный текст с использованием дерева Хаффмана
    decoded_text = ""
    current_node = huffman_tree
    for bit in encoded_text:
        if bit == "0":
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.char:
            decoded_text += current_node.char
            current_node = huffman_tree

    return decoded_text


def huffman_encoding(text):
    # Основная функция для кодирования текста с использованием кода Хаффмана
    frequency_table = build_frequency_table(text)
    huffman_tree = build_huffman_tree(frequency_table)
    encoding_table = build_encoding_table(huffman_tree)
    encoded_text = encode_text(text, encoding_table)
    return encoded_text, huffman_tree


def huffman_decoding(encoded_text, huffman_tree):
    # Основная функция для декодирования закодированного текста с использованием кода Хаффмана
    decoded_text = decode_text(encoded_text, huffman_tree)
    return decoded_text


print(d := huffman_encoding(
        """Ткнул этот человек собачку свою в следы возле двери, сказал «пс» и отошёл. Понюхала собака воздух, повела по толпе глазом (народ, конечно, собрался) и вдруг к бабке Фёкле, с пятого номера, подходит и нюхает ей подол. Бабка за толпу. Собака за юбку. Бабка в сторону — и собака за ней. Ухватила бабку за юбку и не пущает.
Рухнула бабка на колени перед агентом.
— Да,— говорит,— попалась. Не отпираюсь. И,— говорит,— пять ведёр закваски — это так. И аппарат — это действительно верно. Всё,— говорит,— находится в ванной комнате. Ведите меня в милицию.
Ну, народ, конечно, ахнул.
— А шуба? — спрашивают.
— Про шубу,— говорит,— ничего не знаю и ведать не ведаю, а остальное — это так. Ведите меня, казните.
Ну, увели бабку.
Снова взял агент собачищу свою, снова ткнул её носом в следы, сказал «пс» и отошёл.
Повела собачища глазом, понюхала пустой воздух и вдруг к гражданину управдому подходит."""
    )
)

print(huffman_decoding(*d))
