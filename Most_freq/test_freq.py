from subprocess import Popen, PIPE, STDOUT

def test_1():
    p = Popen(['./freq'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate("c++".encode('utf-8'))[0].decode("utf-8").strip()
    assert stdout_data == "2", "For input string 'feels', output should be 2"

def test_2():
    p = Popen(['./freq'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate("feels".encode('utf-8'))[0].decode("utf-8").strip()
    assert stdout_data == "2", "For input string 'c++', output should be 2"

