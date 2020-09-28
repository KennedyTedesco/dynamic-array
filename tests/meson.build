unity_dep = dependency('unity',
    fallback : ['unity', 'unity_dep']
)

test('d_array',
    executable('test_d_array',
        ['test_d_array.c', '../d_array.c'],
        dependencies: unity_dep
    )
)
