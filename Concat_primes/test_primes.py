from subprocess import Popen, PIPE, STDOUT

def test_1():
    p = Popen(['./primes'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate("0".encode('utf-8'))[0].decode("utf-8").strip()
    assert stdout_data == "23571", "For index 0, output should be 23571"

def test_2():
    p = Popen(['./primes'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate("3".encode('utf-8'))[0].decode("utf-8").strip()
    assert stdout_data == "71113", "For index 3, output should be 71113"

