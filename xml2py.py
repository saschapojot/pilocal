import xml.etree.ElementTree as ET


file_path="./myclass.xml"


with open(file_path, 'r', encoding='UTF-8') as file:
    xml_data = file.read()

# Parse the XML
root = ET.fromstring(xml_data)

# Assuming the structure is known and consistent
s_element = root.find('.//s')
members = {child.tag: child.text for child in s_element}

print(members)