"""Keywords for dealing with architecture structure in Building."""
from RPA.Windows import Windows
from robot.libraries import Dialogs

from cad_solutions.building.resources import navigation


def add_new_storey(name: str = "EG", height: str = "2.80", thickness: str = "0.20", other_height: str = "0.75",
                   number: str = "0"):
    """
    Adds a new storey with the specified parameters. Fails if user is not in Gebäudestruktur.

    :param name: Bezeichnung
    :param height: Geschosshöhe
    :param thickness: Deckendicke
    :param other_height: Brüstungshöhe
    :param number: Nummer
    """
    # todo: rename arguments
    navigation.selected_left_tab_should_be("Gebäudestruktur")
    navigation.click_in_project_tree("neues Geschoss")

    windows = Windows()
    # noinspection GrazieInspection
    win = windows.control_window('name:"neues Geschoss"')

    el = windows.get_element("id:1040", root_element=win)  # Nummer
    windows.send_keys(el, number)

    el = windows.get_element("id:1136", root_element=win)  # Bezeichnung
    windows.send_keys(el, name)

    el = windows.get_element("id:1029", root_element=win)  # Geschosshöhe
    windows.send_keys(el, height)

    el = windows.get_element("id:1031", root_element=win)  # Deckendicke
    windows.send_keys(el, thickness)

    el = windows.get_element("id:1034", root_element=win)  # Brüstungshöhe
    windows.send_keys(el, other_height)

    windows.click("name:OK")


def selected_storey_should_be(target_storey) -> None:
    Dialogs.execute_manual_step(
        f'"Selected storey should be" not implemented. '
        f'Please check whether the storey is {target_storey} before proceeding.')


def add_new_room_to_active_storey(room_type: str = "Büro", width: str = "3", length: str = "5") -> None:
    """
    Adds a new room to the storey selected in the building structure tree.

    :param room_type: Type of room
    :param width: width of room
    :param length: length of room
    """
    raise NotImplementedError


def select_room():
    raise NotImplementedError


def set_room_detail(room_detail_name: str, new_value: str):
    raise NotImplementedError


def set_missing_dimension(new_dimension):
    raise NotImplementedError


def select_bauteil(new_bauteil):
    raise NotImplementedError


def select_outer_space(outer_space: str = "außen"):
    raise NotImplementedError
